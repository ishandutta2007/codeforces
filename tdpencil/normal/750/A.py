y, b = [int(i) for i in input().split()]
minutes=240-b;
count=0
if minutes>0:
    for i in range(1, y+1):
        if i*5<=minutes:
            minutes-=i*5;
            count+=1
    print(count)
else:
    print(count)