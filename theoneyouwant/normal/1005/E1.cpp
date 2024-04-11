/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
const long double epsilon = 1e-9;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n,m;
   cin>>n>>m;
   int p[n];
   int j;
   for(int i=0;i<n;i++)
   {
       cin>>p[i];
       if(p[i]==m)
       {
           j=i;
       }
   }
   map<int,int> highlowa,highlowb;
   set<int> s1;
   int ah[j+1]={0};
   int al[j+1]={0};
   int bh[n-j]={0};
   int bl[n-j]={0};
   for(int i=j-1;i>=0;i--)
   {
       if(i==j-1)
       {
           ah[j-1]=0;
           al[j-1]=0;
       }
           
            if(i!=j-1)
           {
               ah[i]=ah[i+1];
               al[i]=al[i+1];
           }
           if(p[i]>m)
           {
               if(i==j-1)
               {
                   ah[i]=1;
               }
               else
               {
                   ah[i]++;
               }
           }
           else
           {
               if(i==j-1)
               {
                   al[i]=1;
               }
               else
               {
                   al[i]++;
               }
           }
           highlowa[ah[i]-al[i]]++;
           s1.insert(ah[i]-al[i]);
       
   }
   for(int i=j+1;i<n;i++)
   {
           if(i!=j+1)
           {
               bh[i-j-1]=bh[i-j-2];
               bl[i-j-1]=bl[i-j-2];
           }
           if(p[i]>m)
           {
               if(i==j+1)
               {
                   bh[0]=1;
               }
               else
               {
                   bh[i-j-1]++;
               }
           }
           else
           {
               if(i==j+1)
               {
                   bl[0]=1;
               }
               else
               {
                   bl[i-j-1]++;
               }
           }
           highlowb[bh[i-j-1]-bl[i-j-1]]++;
   }
 //  cout<<" highlowa "<<highlowa[0]<<" "<<highlowa[-1]<<endl;
 //  cout<<" highlowb "<<highlowb[0]<<" "<<highlowb[1]<<endl;
   ll total=0;
   total+=highlowa[0]+highlowa[1];
   total+=highlowb[0]+highlowb[1];
// cout<<highlowb[0]<<endl<<highlowb[1]<<endl;
   for(set<int>::iterator it=s1.begin();it!=s1.end();it++)
   {
// cout<<highlowb[-(*it)]<<endl;
       total+=(ll)highlowa[(*it)]*(ll)highlowb[(1-(*it))];
       total+=(ll)highlowa[(*it)]*(ll)highlowb[(-(*it))];
   }
   cout<<total+1<<endl;
     return 0;
}