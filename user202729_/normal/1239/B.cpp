#include<iostream>
#include<cassert>
#include<string>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	if(n%2!=0){
		std::cout<<"0\n1 1\n";
		return 0;
	}
	std::string s;s.reserve(n);
	std::cin>>s;
	assert(s.size()==n);
	if(std::count(begin(s),end(s),'(')*2!=n){
		std::cout<<"0\n1 1\n";
		return 0;
	}

	int rotate_len=0;
	{
		int mind=0,mini=0;
		{
			int deg=0;
			for(int i=0;i<n;++i){
				if(s[i]=='(')
					++deg;
				else{
					--deg;
					if(deg<mind){
						mind=deg;
						mini=i+1;
					}
				}
			}
		}
		std::rotate(begin(s),begin(s)+mini,end(s));
		rotate_len=mini;
	}

	int deg_i=0;
	int cur_beauty=0;
	int max_cnt2=0,besti=3,bestj=0 /* so swap is a no-op */;

	int max_cnt1=0,besti1=2,bestk=0 /* so swap is a no-op */;

	for(int i=1,
			j=-1 /* last elem with h=1 (-1 if there is any 0 between) */ ,
			k=0 /* last elem with h=0 */ ,
			cnt1=0, // cnt1 between i & k
			cnt2=0
			;i<=n;++i){
		if(s[i-1]=='('){
			++deg_i;
			if(deg_i==1){
				j=i;
				cnt2=0;
			}
		}else{
			--deg_i;

			if(deg_i==1){
				if(j>=0){
					if(cnt2>max_cnt2){
						max_cnt2=cnt2;
						besti=i;bestj=j;
					}
				}

				j=i;
				cnt2=0;
			}

			if(deg_i==0){
				if(cnt1>max_cnt1){
					max_cnt1=cnt1;
					besti1=i;bestk=k;
				}
				cnt1=0;
				k=i;

				++cur_beauty;
				j=-1;
			}
		}
		assert(deg_i>=0);

		if(deg_i==1) ++cnt1;
		if(deg_i==2) ++cnt2;
	}

	if(cur_beauty+max_cnt2>max_cnt1){
		std::cout<<cur_beauty+max_cnt2<<'\n';
		std::cout<<(besti-1+rotate_len)%n+1<<' '<<(bestj+rotate_len)%n+1<<'\n';
	}else{
		std::cout<<max_cnt1<<'\n';
		std::cout<<(besti1-1+rotate_len)%n+1<<' '<<(bestk+rotate_len)%n+1<<'\n';
	}
}
/*
10 (()()()())
*/