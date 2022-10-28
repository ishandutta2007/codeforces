n=int(input())
s=input()
a=list(map(int,input().split()))
h=[0]*n
ha=[0]*n
har=[0]*n
hard=[0]*n
if s[0]=="h":
    h[0]=a[0]
for i in range(1,n):
    if s[i]=="h":
        h[i]=h[i-1]+a[i]
        ha[i]=ha[i-1]
        har[i]=har[i-1]
        hard[i]=hard[i-1]
    elif s[i]=="a":
        h[i]=h[i-1]
        ha[i]=min(ha[i-1]+a[i],h[i])
        har[i]=har[i-1]
        hard[i]=hard[i-1]
    elif s[i]=="r":
        h[i]=h[i-1]
        ha[i]=ha[i-1]
        har[i]=min(har[i-1]+a[i],ha[i],h[i])
        hard[i]=hard[i-1]
    elif s[i]=="d":
        h[i]=h[i-1]
        ha[i]=ha[i-1]
        har[i]=har[i-1]
        hard[i]=min(hard[i-1]+a[i],h[i],ha[i],har[i])
    else:
        h[i]=h[i-1]
        ha[i]=ha[i-1]
        har[i]=har[i-1]
        hard[i]=hard[i-1]
print(hard[-1])