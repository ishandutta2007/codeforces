I=input
for _ in[0]*int(I()):a,b=map(int,I().split());s=I().strip('0');print(len(s)and
a+sum(min(a,b*len(x))for x in s.split('1')))