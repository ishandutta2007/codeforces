n=int(raw_input())
a=map(int,raw_input().split())
b=[x for x in a if x%2]
print sum(a)-((0 if len(b)%2 else min(b))if len(b)else sum(a))