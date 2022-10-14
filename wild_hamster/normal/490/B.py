d={};e={}
for i in[22814880]*input():a,b=map(int,raw_input().split());e[b]=d[a]=b
l=sum(i-i*(i in e)for i in d);m=d[0]
while l:print l;l,m=m,d.get(l)