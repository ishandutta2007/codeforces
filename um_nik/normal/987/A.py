d = {"purple":"Power", "green":"Time", "blue":"Space", "orange":"Soul", "red":"Reality", "yellow":"Mind"}
s = set()
n = int(input())
for _ in range(n):
	w = input()
	s.add(w)
print(6 - n)
for (key, value) in d.items():
	if key not in s:
		print(value)