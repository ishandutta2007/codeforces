n=int(raw_input())
a=[int(k) for k in raw_input().split()]
a=sorted(a)

print sum([a[2*i+1]-a[2*i] for i in range(n/2)])