#include<iostream>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int mm=110;  
int a,b,c,d,n;  
int f[mm];  
int g[mm][mm];  
void gt()  
{ 
	memset(g,0,sizeof(g));  
  if(b<d)  
    {  
      for(int i=b+1;i<=d;++i)  
        for(int j=1;j<=a;++j)  
        g[i][j]=999;  
    }  
    else  
    {  
      for(int i=d+1;i<=b;++i)  
        for(int j=a+1;j<=c;++j)  
        g[i][j]=999;  
    }  
}  
int main()  
{  
	cin>>a>>b>>c>>d>>n;
	int sum=0;  
    for(int i=0;i<n;++i){  
		cin>>f[i];  
		sum+=f[i];  
	}  
    c+=a;  
    gt(); 
    bool flag=0;  
    int z;int zz=0;  
    if(b<d)z=d;  
    else z=b,flag=1;  
    for(int i=0;i<n;++i)  
    {  
    	for(int j=1;j<=c;++j){
		int ak=j;  
        if(a%2==0)++ak; 
        if(ak&1){
			for(int k=z;k>=1;--k)  
        	if(f[i]&&!g[k][j])  
        	--f[i],g[k][j]=i+1;  
        }
        else  {  
			for(int k=1;k<=z;++k)  
				if(f[i]&&!g[k][j])  
        	    --f[i],g[k][j]=i+1;  
        	}  
		}  
    }
    cout<<"YES\n";  
    for(int i=1;i<=z;++i) {
    	for(int j=1;j<=c;j++){
			if(g[i][j]==999)  cout<<'.';  
			else cout<<char(g[i][j]+'a'-1);  
		}
		cout<<"\n";
	}
}