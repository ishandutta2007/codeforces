def main():
	x, y = map(int, input().split())
	if x == y:
		print('=')
		return
	if x == 1:
		print('<')
		return
	if y == 1:
		print('>')
		return
	if x + y == 6:
		print('=')
		return
	if x == 3:
		print('>')
		return
	if y == 3:
		print('<')
		return
	if x < y:
		print('>')
	else:
		print('<')

main()