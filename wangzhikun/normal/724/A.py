l = ["monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"]
a = l.index(input())
b = (l.index(input())-a+7)%7
if b == 0 or b == 2 or b == 3:
	print("YES")
else:
	print("NO")