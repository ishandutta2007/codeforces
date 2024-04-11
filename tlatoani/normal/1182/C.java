import java.util.*;

public class BeautifulLyrics {
    static final String VOWELS = "aeiou";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        Map<Integer, String[]> map = new HashMap<>();
        List<Pair> pairs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String word = scanner.nextLine();
            //System.out.println("word = '" + word + "'");
            int lastVowel = -1;
            int vowelAmt = 0;
            for (char chara : word.toCharArray()) {
                int vowelIx;
                if ((vowelIx = VOWELS.indexOf(chara)) != -1) {
                    vowelAmt++;
                    lastVowel = vowelIx;
                }
            }
            if (!map.containsKey(vowelAmt)) {
                map.put(vowelAmt, new String[5]);
            }
            String[] array = map.get(vowelAmt);
            if (array[lastVowel] == null) {
                array[lastVowel] = word;
            } else {
                pairs.add(new Pair(array[lastVowel], word));
                array[lastVowel] = null;
            }
        }
        List<Pair> leftovers = new ArrayList<>();
        for (String[] array : map.values()) {
            String curr = null;
            for (String str : array) {
                if (str == null) {
                    continue;
                }
                if (curr == null) {
                    curr = str;
                } else {
                    leftovers.add(new Pair(curr, str));
                    curr = null;
                }
            }
        }
        long answer = Math.min(pairs.size(), (pairs.size() + leftovers.size()) / 2);
        System.out.println(answer);
        while (!leftovers.isEmpty() && !pairs.isEmpty()) {
            Pair first = leftovers.remove(leftovers.size() - 1);
            Pair second = pairs.remove(pairs.size() - 1);
            System.out.println(first.s1 + " " + second.s1);
            System.out.println(first.s2 + " " + second.s2);
        }
        while (pairs.size() > 1) {
            Pair first = pairs.remove(pairs.size() - 1);
            Pair second = pairs.remove(pairs.size() - 1);
            System.out.println(first.s1 + " " + second.s1);
            System.out.println(first.s2 + " " + second.s2);
        }
    }

    static class Pair {
        final String s1;
        final String s2;

        Pair(String s1, String s2) {
            this.s1 = s1;
            this.s2 = s2;
        }
    }
}