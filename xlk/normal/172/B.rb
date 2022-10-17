a,b,m,r=gets.split.map &:to_i;
v=[0]*m;v[r=(a*r+b)%m]+=1 while v[r]!=3;
print 1+v.count(2);