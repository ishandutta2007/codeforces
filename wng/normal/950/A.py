l,r,a=[int(k) for k in raw_input().split(" ")]

res= min(r,l)+ min(abs(l-r),a) + max(0,(a-min(abs(l-r),a)))/2

print res*2