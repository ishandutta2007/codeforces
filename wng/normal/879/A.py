n=int(raw_input())

d=0
for j in range(n):
    a=[int(k) for k in raw_input().split(" ")]
    if d<=a[0]:
        d=a[0]+1
    else:
        d=a[1]*((d-a[0]-1)/a[1]+1)+a[0]+1
  #  print j,d

print d-1