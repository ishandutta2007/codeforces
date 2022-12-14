import java.util.Scanner;

public class B2 {
	static long sumMax(final int[] h) {
		final int n = h.length;
		long result = 0;
		int[] left = new int[n], right = new int[n];
		for (int i = 1; i < n; ++i) { // left[0] = 0;
			if (h[i-1] >= h[i]) {
				left[i] = i;
				continue;
			}
			left[i] = i-1;
			while (left[i]>0 && h[left[i]-1]<h[i])
				left[i] = left[left[i]-1];
		}
		right[n-1] = n-1;
		for (int i = n-2; i >= 0; --i) {
			if (h[i+1] > h[i]) {
				right[i] = i;
				continue;
			}
			right[i] = i+1;
			while (right[i]<n-1 && h[right[i]+1]<=h[i])
				right[i] = right[right[i]+1];
		}
		for (int i = 0; i < n; ++i) {
			result += (((long)h[i]) * (i - left[i] + 1)) * (right[i] - i + 1);
		}
		return result;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long result = 0;
		int[] x = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = in.nextInt();
		}
		result += sumMax(x);
		for (int i = 0; i < n; ++i) x[i] = -x[i];
		result += sumMax(x);
		System.out.println(result);
	}
}