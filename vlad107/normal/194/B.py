n=input()
def gcd(x,y): return x+y if (x*y==0)else gcd(y,x%y)
a=map(int,raw_input().split())
print str([4*x/gcd(4*x,x+1)+1 for x in a]).replace(', ','\n').replace('L','').strip('[]')