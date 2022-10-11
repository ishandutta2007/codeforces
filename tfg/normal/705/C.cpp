#include <cstdio>
#include <vector>

std::vector<bool> read;
std::vector<int> app[300000];
int app_size[300000];//[2];//0=max 1=min_unread

int n,q,unread_notes=0,read_until=0;

int main()
{
	scanf("%i %i", &n, &q);
	/*for(int i=0;i<n;i++)
	{
		app[i]=(int*)malloc(sizeof(int)*q);
		app_size[n][0]=app_size[n][1]=0;

	}*/
	for(int i=0;i<q;i++)
	{

		int type, num;
		scanf("%i %i",&type, &num);
		num--;
		if(type==1)//generate on num
		{
			unread_notes++;
			app[num].push_back(read.size());
			read.push_back(false);
		}
		else if(type==2)//read app num
		{	
			int max=app[num].size();
			for(int j=app_size[num];j<max;j++)
			{
				if(!read[app[num][j]]) unread_notes--;
				read[app[num][j]]=true;
			}
			app_size[num]=max;
		}
		else//read first num
		{
			while(read_until<num+1)
			{
				if(!read[read_until]) unread_notes--;
				read[read_until++]=true;
			}
		}
		printf("%i\n",unread_notes);
	}
	return 0;
}