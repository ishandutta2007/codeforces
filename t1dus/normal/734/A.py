n = int(input())
s = input()
x = s.count('A') - s.count('D') 
if x > 0:
	print("Anton")
elif x < 0:
	print("Danik")
else:
	print("Friendship")