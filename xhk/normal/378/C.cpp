#include<cstdio>
#include<iostream>
using namespace std;

int n,m,k;

struct unit
{int x,y;
};
struct unit q[10000010];

char ga[510][510];
int s,a[510][510];


void bfs()
{int g,i,j,i1,j1,f=0,t=0,w=0;
 
 i=1;
 j=1;
 while(ga[i][j]!='.')
 {if(j<m)
    j++;
  else
  {i++;
   j=1;
  }
 }
 
 //cout<<"j";
 
 t=1;
 w=1;
 
 q[1].x=i;
 q[1].y=j;
 a[i][j]=1;
 f=1;
 
 
 
 
 while(f<s && t<=w)
 {
   //cout<<"hg";    
  
  i1=q[t].x;
  j1=q[t].y;
  
  //cout<<"b"<<" "<<i1<<" "<<j1<<endl;
  
  //cin>>g;
  
  if(i1-1>0 && ga[i1-1][j1]=='.' && a[i1-1][j1]==0)
  {w++;
   q[w].x=i1-1;
   q[w].y=j1;
   a[i1-1][j1]=1;
   f++;
  }
   
  if(f<s && j1-1>0 && ga[i1][j1-1]=='.' && a[i1][j1-1]==0) 
  {w++;
   q[w].x=i1;
   q[w].y=j1-1;
   a[i1][j1-1]=1;
   f++;
  }
  
  if(f<s && i1+1<=n && ga[i1+1][j1]=='.' && a[i1+1][j1]==0) 
  {w++;
   q[w].x=i1+1;
   q[w].y=j1;
   a[i1+1][j1]=1;
   f++;
  }
  
  if(f<s && j1+1<=m && ga[i1][j1+1]=='.' && a[i1][j1+1]==0)
  {w++;
   q[w].x=i1;
   q[w].y=j1+1;
   a[i1][j1+1]=1;
   f++;
  }
  
  t++;
 }

}

int main()
{int i,j,i1,j1;
 
 cin>>n>>m>>k;
 
 for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {cin>>ga[i][j];
    if(ga[i][j]=='.') s++;
   }
 
 s=s-k;
 
 //cout<<"gg";
 
 bfs();
 
 for(i=1;i<=n;i++)
   {for(j=1;j<=m;j++)
    {if(ga[i][j]!='.')
       cout<<ga[i][j];
     else if(ga[i][j]=='.' && a[i][j]==0)
       cout<<'X';
     else
       cout<<'.';
    }
    cout<<endl;
   }
 
 return 0;
}