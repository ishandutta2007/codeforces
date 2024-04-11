a,b,c=map(int,raw_input().split())
d=(a+b+c+4)/5
a,b,c=map(int,raw_input().split())
e=(a+b+c+9)/10
d+=e
if d<=input():print 'YES'
else:print 'NO'