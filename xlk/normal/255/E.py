from bisect import*
input()
a,b=[3,15,81,6723,15**4,15**8],[0,1,2,0,3,1,2]
print "Furlo"if reduce(lambda x,y:x^y,map(lambda x:b[bisect_left(a,x)],map(int,raw_input().split())))else"Rublo"