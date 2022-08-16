from math import sin,pi
n,r = map(int,input().split())
k = sin((n-2)*pi/(n*2))/sin(2*pi/n)
R = r/(2*k-1)
print(R)