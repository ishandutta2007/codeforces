a = list(map(int,input().split()))
mx = max(a)
print(max(0,mx-1-a[0])+max(0 , mx-1-a[2]) + max(0, mx-1-a[1]))