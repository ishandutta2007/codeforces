def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
from math import factorial    
a,b = map_input()
print(factorial(min(a,b)))