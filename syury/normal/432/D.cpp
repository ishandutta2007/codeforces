#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
#include<set>

using namespace std;
typedef unsigned long long int lint;
lint P,M=1000000007;

struct state{
  int len,link,cnt;
  map<char,int>next;
};

vector<state>st;
int last=0,sz=0;

void sa_init(){
  sz=1;
  st.resize(1);
  st[0].len=0;
  st[0].cnt=0;
  st[0].link=-1;
}

void sa_extend(char c){
  int curr=sz;sz++;
  st.resize(sz);
  st[curr].len=st[last].len+1;
  st[curr].cnt=1;
  int p;
  for(p=last;(p!=-1 && !st[p].next.count(c));p=st[p].link){
    st[p].next[c]=curr;
  }
  if(p==-1){st[curr].link=0;}
  else{
    int q=st[p].next[c];
    if(st[q].len==st[p].len+1){st[curr].link=q;}
    else{
      int clone=sz;sz++;
      st.resize(sz);
      st[clone].len=st[p].len+1;
      st[clone].link=st[q].link;
      st[clone].next=st[q].next;
      st[clone].cnt=0;
      for(p=p;(p!=-1 && st[p].next[c]==q);p=st[p].link){st[p].next[c]=clone;}
      st[q].link=st[curr].link=clone;
    }
  }
  last=curr;
}

void sa_build(string s){
  sa_init();
  for (int i=0;i<s.length();i++){sa_extend(s[i]);}
}

void find_cnt(){
  set<pair<int,int>,greater<pair<int,int> > >stset;
  for (int i=0;i<st.size();i++){
    stset.insert(make_pair(st[i].len,i));
  }
  while(!stset.empty()){
    int v=stset.begin()->second;
    if(st[v].link!=-1){st[st[v].link].cnt+=st[v].cnt;}
    stset.erase(stset.begin());
  }
}

vector<int>pos;
vector<int>ans;
int ppos=0;
int curr=0;

void get(string s){
  for (int i=0;i<s.length();i++){
    curr=st[curr].next[s[i]];
    if(ppos<pos.size() && pos[ppos]==i){ans.push_back(st[curr].cnt);ppos++;}
  }
}

void findpref(string s){
  lint cs=0,cp=0;
  int l=s.length();
  srand(time(NULL));
  int tm=rand()%4;
  switch(tm){
    case 0:
      P=31;
      break;
    case 1:
      P=37;
      break;
    case 2:
      P=41;
      break;
    case 3:
      P=43;
      break;
  }
  lint cpow=1;
  for (int i=0;i<l;i++){
    cp+=cpow*(s[i]-'A'+1)%M;
    cp%=M;
    cs=cs*P+(s[l-i-1]-'A'+1);
    cs%=M;
    if(cp==cs){pos.push_back(i);}
    cpow*=P;
    cpow%=M;
  }
}

int main(){
  string s;
  cin>>s;
  sa_build(s);
  find_cnt();
  findpref(s);
  get(s);
  printf("%d\n",pos.size());
  for (int i=0;i<pos.size();i++){
    printf("%d %d\n",pos[i]+1,ans[i]);
  }
  return 0;
}