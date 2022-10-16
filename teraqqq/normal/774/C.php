<?php
    $fl = STDIN;
    fscanf($fl, "%d", $n);
    while ($n > 0) {
        if ($n % 2 == 1) { echo '7'; $n = $n - 3; }
        else { echo '1'; $n = $n - 2; }
    }