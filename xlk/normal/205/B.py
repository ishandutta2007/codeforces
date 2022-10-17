n=input();
a=map(int,raw_input().split())
print sum([max([a[i]-a[i+1],0])for i in range(n-1)])