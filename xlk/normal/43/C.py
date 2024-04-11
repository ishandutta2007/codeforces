n=input()
c=[0]*3
for i in map(int,raw_input().split()):
       c[i%3]+=1
print min(c[1],c[2])+c[0]/2