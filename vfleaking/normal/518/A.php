<?php
fscanf(STDIN, "%s", $s);
fscanf(STDIN, "%s", $t);

if (strcmp($s, $t) >= 0) {
	print "No such string";
} else {
	$l = strlen($s);
	for ($i = $l - 1; $i >= 0; $i--) {
		if ($s[$i] == 'z') {
			$s[$i] = 'a';
		} else {
			$s[$i] = chr(ord($s[$i]) + 1);
			break;
		}
	}
	if (strcmp($s, $t) == 0) {
		print "No such string";
	} else {
		print $s;
	}
}