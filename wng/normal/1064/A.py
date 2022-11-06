a,b,c=sorted([int(k) for k in raw_input().split(" ")])

print max(0,c-b-a+1)