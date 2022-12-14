#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	int n;std::cin>>n;
	std::vector<std::vector<int8_t>> v(n,std::vector<int8_t>(n,-1));
	auto process=[&](int x1,int y1,int x2,int y2){
		auto const s=v[x1][y1];
		auto& t=v[x2][y2];
		assert(s>=0&&t<0);

		if(x1+y1>x2+y2){std::swap(x1,x2);std::swap(y1,y2);}
		assert(x2+y2-x1-y1==2 && x1<=x2 && y1<=y2);
		std::cout<<"? "<<x1+1<<' '<<y1+1<<' '<<x2+1<<' '<<y2+1<<std::endl;
		int ans;
		std::cin>>ans;
		t=int8_t(s^1^ans);
	};

	v[0][0]=v[0][1]=1;
	v[n-1][n-1]=0;

	for(int c=2;c<n;++c)
		process(0,c-2, 0,c);
	for(int c=1;c<n;++c)
		process(0,c-1, 1,c);
	process(1,2, 1,0);

	for(int r=2;r<n;++r)
		for(int c=0;c<n;++c)
			if(!(r==n-1&&c==n-1))
				process(r-2,c, r,c);

	for(int x2=1;x2<n;++x2)
	for(int y2=2;y2<n;++y2){
		int const x1=x2-1,y1=y2-2;
		auto const pal1=v[x1][y1]==v[x2][y2] && (v[x2][y1]==v[x2][y1+1]||v[x2][y1+1]==v[x1][y1+1]||v[x1][y1+1]==v[x1][y2]);
		auto const pal2=v[x1][y1]!=v[x2][y2] && (v[x2][y1]!=v[x2][y1+1]||v[x2][y1+1]!=v[x1][y1+1]||v[x1][y1+1]!=v[x1][y2]);
		if(pal1!=pal2){
			std::cout<<"? "<<x1+1<<' '<<y1+1<<' '<<x2+1<<' '<<y2+1<<std::endl;
			int ans;std::cin>>ans;
			if(ans==pal2){
				for(int r=0;r<n;++r)
					for(int c=!(r&1);c<n;c+=2)
						v[r][c]^=1;
			}
			goto output;
		}
	}

	assert(false);

output:
	std::cout<<"!\n";
	for(int r=0;r<n;++r){
		for(int c=0;c<n;++c)
			std::cout<<char('0'+v[r][c]);
		std::cout<<'\n';
	}
}