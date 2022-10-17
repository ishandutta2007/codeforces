s=gets.chomp
x=0
s.each_byte{|c|
	y=("%08b"%c).reverse.to_i(2);
	p x-y&255
	x=y
}