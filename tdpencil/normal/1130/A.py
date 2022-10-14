k=l=(int(input())-1)//2
for x in map(int,input().split()):k-=x>0;l-=x<0
print((0,1,-1,1)[(k<0)+2*(l<0)])