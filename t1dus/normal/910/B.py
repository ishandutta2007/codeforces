'''input
6
4
2
'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
 
def f(n,a,b,left,cnta = 4,cntb = 2):
	if(cnta == 0 and cntb == 0): return 0
	if(cnta < 0 or cntb < 0): return 100000000000000000000
	if a <= left and cnta and b <= left and cntb:
		return min(f(n,a,b,left-a,cnta-1,cntb),f(n,a,b,left-b,cnta,cntb-1))
	if a <= left and cnta:
		return f(n,a,b,left-a,cnta-1,cntb)
	if b <= left and cntb:
		return f(n,a,b,left-b,cnta,cntb-1)
	return 1+min(f(n,a,b,n-a,cnta-1,cntb),f(n,a,b,n-b,cnta,cntb-1))			

n = int(input())
a = int(input())
b = int(input())
print(f(n,a,b,0))