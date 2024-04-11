i=lambda:map(int,raw_input().split())
i();a=i();l=i()
v=sum(a[min(l)-1:max(l)-1])
print min(v,sum(a)-v)