import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.IntStream;

public class Solution {

	private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int nm[] = readInts(reader);
		int n = nm[0], m = nm[1];
		
		int[] caffine = readInts(reader);
		
		if(Arrays.stream(caffine).asLongStream().sum() < m) {
			System.out.println(-1);
			return;
		}
		
		Arrays.sort(caffine);
		
		int champResult = m;
		int low = 1, high = n;
		while(low <= high) {
			int days = (low + high) / 2;
			if(isPossible(caffine, days, m)) {
				champResult = days;
				high = days - 1;
			} else {
				low = days + 1;
			}
			
			
			
		}
		System.out.println(champResult);
	}
	
	public static int[] readInts(BufferedReader reader) throws IOException {
		return toIntArray(reader.readLine());
	}
	
	public static int[] toIntArray(String s) {
		String[] nums = s.split("\\s");
		return IntStream.range(0, nums.length)
			.map(index -> Integer.parseInt(nums[index]))
			.toArray();
	}

	private static boolean isPossible(int[] caffine, int days, int totalNoOfPages) {
		@SuppressWarnings("unchecked")
		ArrayList<Integer>[] buckets = new ArrayList[days];
		for(int i = 0; i < days; i++) {
			buckets[i]  = new ArrayList<>();
		}
		
		int j = caffine.length - 1, i = 0;
		while(j >= 0 && caffine[j] - (i / days) > 0) {
			buckets[i % days].add(caffine[j] - (i / days));
			i++;
			j--;
		}
		long pagesWritten = 0;
		for(int counter = 0; counter < buckets.length; counter++) {
			pagesWritten += buckets[counter].stream().mapToLong(in -> (long)in).reduce(0, (a, b) -> a + b);
		}
		
		return pagesWritten >= totalNoOfPages;
	}
	
	
	
	
	
}