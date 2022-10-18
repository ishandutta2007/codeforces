<?php
function count_letters($s, &$cnt) {
	$cnt = array();
	for ($i = 0; $i < 26; $i++) {
		$cnt[] = array(0, 0);
	}

	$l = strlen($s);
	for ($i = 0; $i < $l; $i++) {
		$c = ord($s[$i]);
		if (ord('a') <= $c && $c <= ord('z')) {
			$cnt[$c - ord('a')][0]++;
		} else {
			$cnt[$c - ord('A')][1]++;
		}
	}
}

fscanf(STDIN, "%s", $s);
fscanf(STDIN, "%s", $t);

count_letters($s, $cnt_s);
count_letters($t, $cnt_t);

$res_a = 0;
$res_b = 0;

for ($c = 0; $c < 26; $c++) {
	for ($k = 0; $k <= 1; $k++) {
		$d = min($cnt_s[$c][$k], $cnt_t[$c][$k]);
		$cnt_s[$c][$k] -= $d;
		$cnt_t[$c][$k] -= $d;
		$res_a += $d;
	}
}
for ($c = 0; $c < 26; $c++) {
	for ($k = 0; $k <= 1; $k++) {
		$d = min($cnt_s[$c][$k], $cnt_t[$c][$k ^ 1]);
		$cnt_s[$c][$k] -= $d;
		$cnt_t[$c][$k ^ 1] -= $d;
		$res_b += $d;
	}
}

echo "$res_a $res_b\n";