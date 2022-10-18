#include<bits/stdc++.h>
#define ll long long
#define N 200005

int n;

std::map<std::string,std::vector<std::string>> s;

int m,l;

ll cnt,ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		std::string a,b;
		std::cin>>a;
		l=a.length();
		b=a;
		std::sort(b.begin(),b.end());
		s[b].push_back(a);
	}
	for(auto &[u,v]:s){
		m=v.size();
		ans+=cnt*m*1337;
		cnt+=m;
		if(m<=200*l){
			for(int i=0;i<m;i++)
				for(int j=i+1;j<m;j++)
					if(v[i]!=v[j]){
						int L=0,R=l-1;
						while(v[i][L]==v[j][L])
							L++;
						while(v[i][R]==v[j][R])
							R--;
						bool f=1,g=1;
						for(int k=L;k<R;k++){
							f&=v[i][k]<=v[i][k+1];
							g&=v[j][k]<=v[j][k+1];
						}
						ans+=1+!(f||g);
					}
		}
		else{
			std::map<std::string,bool> vis;
			for(auto &x:v)
				vis[x]=1;
			ans+=1ll*m*(m-1);
			for(auto &x:v)
				for(int i=0;i<l;i++)
					for(int j=i+1;j<l;j++){
						auto y=x;
						std::sort(y.begin()+i,y.begin()+j+1);
						if(x[i]!=y[i]&&x[j]!=y[j]&&vis[y])
							ans--;
					}
		}
	}
	printf("%lld\n",ans);
}