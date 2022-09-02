#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		string str(n,'.');
		auto ask=[&](string s)->vector<int>{
			cout<<"? "<<s<<endl;
			int l;
			cin>>l;
			vector<int>re;
			rep(_,0,l-1){
				int x;
				cin>>x;
				--x;
				re.pb(x);
				rep(i,0,SZ(s)-1){
					str[x+i]=s[i];
				}
			}
			return re;
		};
		if(n==4){
			int flg=0;
			flg|=!ask("CC").empty();
			flg|=!ask("CH").empty();
			flg|=!ask("CO").empty();
			flg|=!ask("HO").empty();
			if(count(str.begin(),str.end(),'.')==0){
				cout<<"! "<<str<<endl;
			}else{
				int l=-1,r=-1;
				rep(i,0,n-1)if(str[i]!='.'){l=i;break;}
				per(i,n-1,0)if(str[i]!='.'){r=i;break;}
				if(l!=-1){
					while(l>0){
						for(auto&c:{'H','O'}){
							str[l-1]=c;
							if(c=='O')break;
							auto re(ask(str.substr(l-1,r-l+2)));
							if(find(re.begin(),re.end(),l-1)!=re.end()){
								break;
							}
						}
						l-=1;
					}
					while(r<n-1){
						for(auto&c:{'C','H','O'}){
							str[r+1]=c;
							if(c=='O')break;
							auto re(ask(str.substr(l,r-l+2)));
							if(find(re.begin(),re.end(),l)!=re.end()){
								break;
							}
						}
						r+=1;
					}
				}else{
					auto re=ask("OOO");
					if(!re.empty()&&re[0]==0){
						if(find(re.begin(),re.end(),1)!=re.end()){
							str="OOOO";
						}else{
							re=ask("OOOH");
							if(re.empty()){
								str="OOOC";
							}
						}
					}else{
						re=ask("OOH");
						if(find(re.begin(),re.end(),0)==re.end()){
							re=ask("OHH");
							if(find(re.begin(),re.end(),0)==re.end()){
								str[0]='H',str[1]='H',str[2]='H';
							}
						}
						str[n-1]='C';
						re=ask(str);
						if(re.empty()){
							str[n-1]='H';
						}
					}
				}
				cout<<"! "<<str<<endl;
			}
		}else{
			ask("CC");
			ask("CH");
			ask("CO");
			ask("HH");
			ask("OH");
			rep(i,1,n-2)if(str[i]=='.')str[i]='O';
			vector<char>v0=str[0]=='.'?vector<char>{'H','O'}:vector<char>{str[0]};
			vector<char>v1=str[n-1]=='.'?vector<char>{'C','O'}:vector<char>{str[n-1]};
			bool flg=0;
			for(auto&c0:v0)if(!flg){
				for(auto&c1:v1)if(!flg){
					str[0]=c0,str[n-1]=c1;
					if(c0==v0.back()&&c1==v1.back()){
						break;
					}
					auto re(ask(str));
					if(!re.empty())flg=1;
				}
			}
			cout<<"! "<<str<<endl;
		}
		int x;
		cin>>x;
		//assert(x==1);
	}
	return 0;
}