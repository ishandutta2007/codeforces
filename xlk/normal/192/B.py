n=input()
a=map(int,raw_input().split())
print min([a[0],a[-1]]+[max(a[i],a[i+1])for i in range(n-1)])