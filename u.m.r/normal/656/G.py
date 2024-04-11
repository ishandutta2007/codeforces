#"kitten"
n,m,k=map(int,raw_input().split())
f=[0]*m
for i in range(n):
    f=map(lambda x,y:(x=='Y')+y,list(raw_input()),f)
print reduce(lambda x,y:x-(y<k),f,m);