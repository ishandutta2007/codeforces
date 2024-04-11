n=[int(k) for k in raw_input().split(" ")][0]
a=[-1]+[int(k)-1 for k in raw_input().split(" ")]

i=n-1
res=[i+1]

while a[i]>=0:
    i=a[i]
    res+=[i+1]

print " ".join([str(k) for k in res[::-1]])