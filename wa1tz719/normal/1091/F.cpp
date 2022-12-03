#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long a[100005];
char b[100005];
long long grass_meter[100005];
long long water_meter[100005];
long long energy_left[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    scanf("%s",b);
    bool have_water=false;
    long long energy=0;
    long long dist=0;
    grass_meter[0]=0;
    water_meter[0]=0;
    for (i=0;i<n;i++)
    {
        grass_meter[i+1]=grass_meter[i];
        water_meter[i+1]=water_meter[i];
        if (b[i]=='W')
        {
            have_water=true;
            dist+=a[i]*3;
            energy+=a[i];
            water_meter[i+1]+=a[i];
        }
        else if (b[i]=='G')
        {
            dist+=a[i]*5;
            energy+=a[i];
            grass_meter[i+1]+=a[i];
        }
        else
        {
            dist+=a[i];
            energy-=a[i];
            if (energy<0)
            {
                if (have_water)
                {
                    dist-=3*energy;
                    energy=0;
                }
                else
                {
                    dist-=5*energy;
                    energy=0;
                }
            }
        }
        energy_left[i+1]=energy;
    }
    if (energy==0)
    {
        cout<<dist<<endl;
    }
    else
    {
        //We should spend these enrgy.
        for (i=n-1;i>=1;i--)
        {
            energy_left[i]=min(energy_left[i],energy_left[i+1]);
        }
        for (i=n;i>=1;i--)
        {
            energy_left[i]=energy_left[i]-energy_left[i-1];
        }
        long long grass_dist=0;
        long long left_energy=0;
        for (i=0;i<n;i++)
        {
            left_energy+=energy_left[i+1];
            if (b[i]=='G')
            {
                grass_dist+=a[i];
            }
            if (grass_dist>=left_energy)
            {
                dist-=2*left_energy;
                left_energy=0;
                grass_dist=0;
            }
            else
            {
                dist-=2*grass_dist;
                left_energy-=grass_dist;
            }
            if (grass_dist>=left_energy)
            {
                dist-=2*left_energy;
                left_energy=0;
                grass_dist=0;
            }
            else
            {
                dist-=2*grass_dist;
                left_energy-=grass_dist;
            }
            grass_dist=0;
        }
        dist-=left_energy;
        cout<<dist<<endl;
    }
    return 0;
}