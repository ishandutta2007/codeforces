#include <bits/stdc++.h>
using namespace std;
int cnt[100];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		int n=s.size();
		s=' '+s;
		int flag=0;
		for(int i=2;i<=n;i++)
		{
			if(s[i]!=s[i-1]) flag=1;
		}
		if(!flag)
		{
			cout << s.substr(1) << "\n";
			continue;
		}//zzzzzzz 
		for(int i=0;i<=30;i++) cnt[i]=0;
		for(int i=1;i<=n;i++)
			++cnt[s[i]-'a'];
		flag=0;
		for(int i=0;i<=30;i++)
		{
			if(cnt[i]==1)
			{
				cout << (char)(i+'a');
				--cnt[i];
				for(int j=0;j<=30;j++)
				{
					while(cnt[j]--)
					{
						cout << (char)(j+'a');
					}
				}
				flag=1;
				cout << "\n";//zaaaabbbbccccdddd
				break;
			}
		}
		if(flag) continue;
		int mn=1e9,pos=0,P=0;
		for(int i=0;i<=30;i++)
		{
			if(cnt[i]>n/2+1)
			{
				flag=1;
				P=i;//abaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacbbcccddeeeff
			 } 
			if(cnt[i]<=n/2+1&&cnt[i])
			{
				mn=cnt[i],pos=i;
				break;
			}
		}
		if(flag)
		{
			flag=0;
			for(int i=0;i<=30;i++)
			{
				if(i!=pos&&i!=P&&cnt[i])
				{
					flag=i;
					break;
				}
			}
			if(flag)
			{
				cout << (char)(P+'a') << (char)(pos+'a');
				--cnt[P];
				while(cnt[P]--) cout << (char)(P+'a');
				cout << (char)(flag+'a');
				--cnt[pos];
				--cnt[flag];
				for(int j=0;j<=30;j++)
				{
					while(cnt[j]>0)
					{
						--cnt[j];
						cout << (char)(j+'a');
					}
				}
				cout << "\n";
				continue;
			}
				cout << (char)(P+'a');
				while(cnt[pos]--) cout << (char)(pos+'a');
				--cnt[P];
				for(int j=0;j<=30;j++)
				{
					while(cnt[j]>0)
					{
						--cnt[j];
						cout << (char)(j+'a');
					}
				}
				cout << "\n";
				continue;
		}
		cout << (char)(pos+'a') << (char)(pos+'a');
		int x=cnt[pos]-2,y=n-cnt[pos];
		cnt[pos]-=2;
		flag=0;
		for(int i=0;i<pos;i++)
		{
			if(cnt[i])
			{
				while(y>=x&&cnt[i])
				{
					--y,cnt[i]--;
					cout << (char)(i+'a');
					flag=1;
				}
			}
		}
		if(flag&&cnt[pos])
		{
			--cnt[pos];
			cout << (char)(pos+'a');
		}
		for(int i=0;i<=30;i++)
		{
			if(cnt[i]&&i!=pos)
			{
				while(cnt[i]--)
				{
					cout << (char)(i+'a');
					if(cnt[pos])
					{
						--cnt[pos];
						cout << (char)(pos+'a');
					}
				}
			}
		}
		cout << "\n";
	}
	return 0;
}