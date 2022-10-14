#include <iostream>
#include<map>
#include<algorithm>
#include<string>
#include <vector>
#include<math.h>
#include<set>
using namespace std;
void countS(vector<int>& arr, vector<int>& p)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cin >> arr[i];
		if (arr[i] == 1)
			p[1]++;
		else if (arr[i] == 2)
			p[2]++;
		else if (arr[i] == 3)
			p[3]++;
		else if (arr[i] == 4)
			p[4]++;
		else if (arr[i] == 5)
			p[5]++;
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int>arr1(n), arr2(n),a1(6,0),a2(6,0);
	countS(arr1,a1);
	countS(arr2,a2);
	for(int i = 1;i<6;i++)
	{
		if((a1[i]%2==0&&a2[i]%2==0)||(a1[i]%2!=0&&a2[i]%2!=0))
			continue;
		cout<<-1<<endl;
		return 0;
	}
	int count = 0;
	for(int i = 1;i<6;i++)
	{
		if(a1[i]!=a2[i])
		{
			if(a1[i] < a2[i])
			{
				for(int j = 1;j<6;j++)
				{
					if(j==i)
						continue;
					if(a1[j]>a2[j])
					{
						while(a1[i]!=a2[i]&&a1[j]!=a2[j])
						{
							a2[i]--;
							a1[i]++;
							a1[j]--;
							a2[j]++;
							count++;
						}
						if(a1[i]==a2[i])
							break;
					}

				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
//1 3 4 4 0
//3 3 2 0 0