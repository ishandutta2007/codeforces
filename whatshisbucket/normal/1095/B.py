n=int(input())
a=list(map(int,input().split()))
large=0
large2=0
small=1000000
small2=1000000
for i in range(n):
    if a[i]>large:
        large2=large
        large=a[i]
    elif a[i]>large2:
        large2=a[i]
    if a[i]<small:
        small2=small
        small=a[i]
    elif a[i]<small2:
        small2=a[i]
print(min(large2-small,large-small2))