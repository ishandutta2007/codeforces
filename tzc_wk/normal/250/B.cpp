#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string f(string t)
{
	string ans="";
	for(int i=0;i<4-t.size();i++)
	{
		ans.push_back('0');
	}
	ans=ans+t;
	return ans;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char s[100];
        char t[5];
        memset(t,0,sizeof(t));
        cin>>s;
        int len=strlen(s),k=0 ;
        int ans=0,tt=0;
        for(int i=0; i<len; i++)
            if(s[i]==':') ans++;
        ans=7-ans;
        if(ans<0)
            for(int i=0; i<len; i++)
            {
                if(s[i]==':'&&s[i+1]==':')
                {
                    for(int j=i+1; j<len; j++)
                        s[j]=s[j+1];
                    len--;
                    break;
                }
 
            }
            for(int i=0; i<len; i++)
            {
                if(s[i]==':')
                {
                    cout<<f(t);
                    k++;
                    if(k<8) cout<<":";
                    if(s[i+1]==':')
                        for(int j=1; j<=ans; j++)
                        {
                            printf("0000");
                            k++;
                            if(k<8) cout<<":";
                        }
                    memset(t,0,sizeof(t));
                    tt=0;
                }
                else
                    t[tt++]=s[i];
            }
        cout<<f(t);
        cout<<endl;
    }
    return 0;
}//