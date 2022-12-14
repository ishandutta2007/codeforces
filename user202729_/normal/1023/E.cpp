//http://codeforces.com/contest/1023/problem/E
#include<iostream>
#include<string>

int main(){
	int n;std::cin>>n;
	int r=1,c=1;
	std::string ans;ans.reserve(2*n);
	while(r+c<n+1){
		// it's guaranteed that result of query (r,c) - (n,n) is true
		std::cout<<"? "<<r+1<<' '<<c<<' '<<n<<' '<<n<<'\n'; // try move down
		char result;std::cin>>result;std::cin.ignore(3,'\n');
		switch(result){
		case 'Y': ++r;ans+='D';break;
		case 'N': ++c;ans+='R';break;
		case 'B': return 0;
		}
	}
	ans.resize(2*n-2);
	int r2=n,c2=n;
	for(int i=n-1;i--;){
		// it's guaranteed that result of query (r,c) - (r2,c2) is true
		char lastmove=ans[i];
		switch(lastmove){
		case 'D': --r;break;
		case 'R': --c;break;
		}
		// try moving left
		char result;
		if(c<c2){
			std::cout<<"? "<<r<<' '<<c<<' '<<r2<<' '<<c2-1<<'\n';
			std::cin>>result;std::cin.ignore(3,'\n');
		}else{
			result='N';
		}
		switch(result){
		case 'Y': --c2;ans[i+n-1]='R';break;
		case 'N': --r2;ans[i+n-1]='D';break;
		case 'B': return 0;
		}
	}
	std::cout<<"! "<<ans<<'\n';
}