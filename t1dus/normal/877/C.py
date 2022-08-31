'''input
4
'''


from math import sqrt

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())
a = []
for i in range(2,n+1,2): a.append(i)
for i in range(1,n+1,2): a.append(i)
for i in range(2,n+1,2): a.append(i)

print(len(a))
for i in a: print(i,end=' ')