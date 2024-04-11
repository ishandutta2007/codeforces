gets
ar = gets.chomp!.split ' '

part = 0
ok = true
lst = -1
ar.each do |ai|
	ai = ai.to_i
	if part == 0
		if lst == ai
			part = 1
		elsif lst > ai
			part = 2
		end
	elsif part == 1
		if lst > ai
			part = 2
		elsif lst < ai
			ok = false
		end
	else
		if lst <= ai
			ok = false
		end
	end
	lst = ai
end

puts(if ok; "YES"; else; "NO"; end)