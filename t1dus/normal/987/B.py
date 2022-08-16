def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
x,y = map_input()
if((x <= 5 and y <= 5) or x == 1 or y == 1):
	if(x**y > y**x): print(">")
	elif (x**y == y**x): print("=")
	else: print("<")
else:
	if(x < y): print(">")
	elif x == y: print("=")
	else: print("<")