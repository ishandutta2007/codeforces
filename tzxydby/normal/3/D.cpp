#include<bits/stdc++.h>
using namespace std;
const int N=50005; 
struct data
{
    int delta;
    char *p;
    bool operator<(const data &b)const 
	{
        return delta>b.delta;
    }
}t;
priority_queue<data>q;
char s[N];
int main() 
{
    int sum=0;
    long long ans=0;
    scanf("%s",s);
    for(int i=0;s[i]&&ans!=-1;i++) 
	{
        if(s[i]=='(')
            sum++;
        else 
		{
            sum--;
            if(s[i]=='?') 
			{
				int a,b;
                scanf("%d%d",&a,&b);
                t.delta=a-b;
                t.p=s+i;
                q.push(t);
                s[i]=')';
                ans+=b;
            }
        }
        if(sum<0)
		{
            if(q.empty())
                ans=-1;
            if(ans!=-1) 
			{
                sum+=2;
                t=q.top();
                q.pop();
                *t.p='(';
                ans+=t.delta;
            }
        }
    }
    if(sum)
        ans=-1;
    printf("%I64d\n",ans);
    if(ans!=-1)
        printf("%s\n",s);
    return 0;
}