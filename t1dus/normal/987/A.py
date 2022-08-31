'''input
4
red
purple
yellow
orange

'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
d = {}
d["purple"] = "Power"
d["green"] = "Time"
d["blue"] = "Space"
d["orange"] = "Soul"
d["red"] = "Reality"
d["yellow"] = "Mind"

a = []
for i in range(n): a.append(input())
b = []
for i in d:
	if i not in a:
		b.append(d[i])
print(len(b))
for i in b: print(i)