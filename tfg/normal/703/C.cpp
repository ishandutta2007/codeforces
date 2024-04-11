#include <cstdio>
#include <algorithm>

struct Point
{
	long long int x, y;
};

double bus_v, p_v;
long long int n, w;

int most_left=0, most_right=0, most_down=0, most_up=0;

Point bus[10010];

bool left(int a, int b)
{
	if(bus[a].x<bus[b].x) return true;
	else
	{
		if(bus[a].x==bus[b].x && bus[a].y>bus[b].y) return true;
		else return false;
	}
}

bool right(int a, int b)
{
	if(bus[a].x>bus[b].x) return true;
	else
	{
		if(bus[a].x==bus[b].x && bus[a].y<bus[b].y) return true;
		else return false;
	}
}

bool down(int a, int b)
{
	if(bus[a].y<bus[b].y) return true;
	else
	{
		if(bus[a].y==bus[b].y && bus[a].x>bus[b].x) return true;
		else return false;
	}
}

bool up(int a, int b)
{
	if(bus[a].y>bus[b].y) return true;
	else
	{
		if(bus[a].y==bus[b].y && bus[a].x<bus[b].x) return true;
		else return false;
	}
}



double reach_time(int i)
{
	return ((double)bus[i].x)/bus_v;
}

double reach_time_p(int y)
{
	return ((double)y)/p_v;
}

double reach_on_time(double cur_time)
{
	return ((double)cur_time)*p_v;
}

int main()
{
	scanf("%lli %lli %lf %lf", &n, &w, &bus_v, &p_v);
	for(int i=0;i<n;i++)
	{
		scanf("%lli %lli", &bus[i].x, &bus[i].y);
		if(left(i, most_left)) most_left=i;
		if(right(i, most_right)) most_right=i;
		if(down(i, most_down)) most_down=i;
		if(up(i, most_up)) most_up=i;
	}
	bool can_left=true;
	double right_path=0.0;
	double ans=0;

	/*printf("most_left:%i\n",most_left);
	printf("most_right:%i\n",most_right);
	printf("most_down:%i\n",most_down);
	printf("most_up:%i\n",most_up);*/
	//right path
	right_path+=std::max(reach_time(most_down),reach_time_p(bus[most_down].y));
	int cur_pos=bus[most_down].y;
	//printf("right path is %.7f, cur_pos is %i\n", right_path, cur_pos);
	for(int i=(most_down+1)%n;i!=(most_right+1)%n;i=(i+1)%n)
	{
		//printf("comparing %.7f and %.7f\n",reach_time(i)-right_path,(reach_time_p(bus[i].y)-reach_time_p(cur_pos)));
		right_path+=std::max(reach_time(i)-right_path, reach_time_p(bus[i].y)-reach_time_p(cur_pos));
		cur_pos=bus[i].y;
		//printf("right path is %.7f, cur_pos is %i\n", right_path, cur_pos);
	}
	right_path+=reach_time_p(w)-reach_time_p(bus[most_right].y);
	//printf("right path is %.7f, cur_pos is %i\n", right_path, w);

	//left path
	cur_pos=0;
	for(int i=(most_left);i!=(most_up+n-1)%n && can_left;i=(i-1+n)%n)
	{
		//printf("comparing %.7f and %.7f\n",(reach_time_p(bus[i].y)-reach_time_p(cur_pos)),reach_time(i)-reach_time_p(cur_pos));
		if((reach_time_p(bus[i].y)-reach_time_p(cur_pos))>reach_time(i)-reach_time_p(cur_pos)) can_left=false;
		cur_pos=bus[i].y;
	}
	//printf("it goes to the %s.\n",can_left?"left":"right");
	if(can_left) printf("%.10lf",reach_time_p(w));
	else printf("%.10lf",right_path);
}