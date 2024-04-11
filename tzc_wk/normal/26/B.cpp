#include <bits/stdc++.h>
using namespace std;
map<char,int> num;
int main()
{
   string s;
   cin>>s;
   int ans=0 ;
   for(int i=0;i<s.size();i++ )
   {
       if(s[i]=='(') num['(']++ ;
       if(s[i]==')')
       {
           if(num['(']>0)
           {
               ans+=2;
			   num['(']--;
           }
       }
   }
   cout<<ans<<endl;
   return 0;
}