f=lambda x,y:55 if x+y=='??' else int(y)+1 if x=='?' else 10-int(x) if y=='?' else x<=y
g=lambda x,y:10 if x+y=='??' else (x==y)|(x=='?')|(y=='?')
n=input()
a=raw_input()
b=raw_input()
print ((10**((a+b).count('?')))-reduce(lambda r,x:r*x,map(lambda x,y:f(x,y),a,b),1)-reduce(lambda r,x:r*x,map(lambda x,y:f(y,x),a,b),1)+reduce(lambda r,x:r*x,map(lambda x,y:g(y,x),a,b),1))%1000000007