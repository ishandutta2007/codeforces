n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]

res="YES"
while a:
    mm=a[0]
    id=0
    for i in range(1,len(a)):
        if a[i]>mm:
            mm=a[i]
            id=i
        if abs(a[i]-a[i-1])>1:
            res="NO"
            break
    a=a[:id]+a[id+1:]
print res