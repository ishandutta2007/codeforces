n=[int(k) for k in raw_input().split(" ")][0]
a=[int(k) for k in raw_input().split(" ")]

a=sorted(a)

res= a[-1]-a[0]+1-n

print res