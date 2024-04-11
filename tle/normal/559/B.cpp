#include<iostream>   
#include<cstdio>
#include<cstdlib>    
#include<algorithm>  
#include<cstring>  
using namespace std;  
string a,b;
int T;
int Dfs(int x,int y,int s,int t)  
{  
    int Mid=y-x+1;  
    if(Mid&1)  
    {  
        for(int i=0;i<Mid;++i)  
        {  
            if(a[i+x]!=b[i+s])  
                return 0;  
        }  
        return 1;  
    }  
    Mid/=2;  
    if(Dfs(x,x+Mid-1,s,s+Mid-1)&&Dfs(x+Mid,y,s+Mid,t))  
        return 1;  
    if(Dfs(x+Mid,y,s,s+Mid-1)&&Dfs(x,x+Mid-1,s+Mid,t))  
        return 1;  
    return 0;  
}  
  
int main()  
{    
        cin>>a>>b;
        if(a==b) {puts("YES");return 0;}
        int len=a.length();  
        if(Dfs(0,len-1,0,len-1))
            puts("YES");  
        else puts("NO");
    return 0;
}